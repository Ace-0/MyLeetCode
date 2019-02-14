import argparse
import requests
import json
import csv
import os

import update_record

def main():
    target_dir = os.getcwd()
    tool_dir = 'tools'
    cookie_file = os.path.join(target_dir, tool_dir, 'cookie.txt')
    record_file = os.path.join(target_dir, tool_dir, 'record.json')
    leetcode_list_file = os.path.join(target_dir, tool_dir, 'problem_list.csv')
    leetcode_url = 'https://leetcode.com/api/problems/algorithms/'

    parser = argparse.ArgumentParser(description='Process some arguments.')

    # ID of the question
    parser.add_argument('--id', '-i',
                        type=int,
                        default=0,
                        help='id of tht question (default: 0)')
    # Template file to use
    parser.add_argument('--template', '-t',
                        type=argparse.FileType('r'),
                        default=os.path.join(target_dir, tool_dir, 'Template.py'),
                        help='template file to use (default: Template)'
                        )
    # Update from the Internet or not
    parser.add_argument('--update', '-u',
                        action='store_true',
                        help='update from the Internet or not (default: Not update)')

    args = parser.parse_args()

    question_list = get_question_list(leetcode_list_file, args.update, record_file, leetcode_url, cookie_file)

    question = search_question_from_list(args.id, question_list)

    new_file_name = create_solution_file(question, target_dir, args.template)

    print('===============================================================')
    print('|')
    print('| Successfully create', new_file_name)
    print('|')
    print('===============================================================')

def update_list_file(list_file, record_file, url, cookie_file):
    '''Update file of question list using APIs of OJ.

    Args:
        url (str): Url of APIs.
        list_file (str): File name of the file used to save question list.

    '''
    cookie = update_record.load_cookie(cookie_file)
    json_object = update_record.get_record_and_save(record_file, url, cookie)

    question_list = json_object['stat_status_pairs']
    question_list.sort(key=lambda p: p['stat']['frontend_question_id'])

    with open(list_file, 'w') as csv_file:
        field_names = ['question_id', 'question__title', 'question__title_slug', 'question__article__live', 'total_submitted',
                        'is_new_question', 'question__article__slug', 'question__hide', 'frontend_question_id', 'total_acs']
        writer = csv.DictWriter(csv_file, fieldnames=field_names)
        writer.writeheader()
        for question in question_list:
            writer.writerow(question['stat'])

def get_question_list(list_file, update, record_file, url, cookie_file):
    '''Get question list from file.

    Args:
        url (str): Url of APIs.
        list_file (str): File name of the file where question list is stored.
        update (bool): If the file needs to be updated.

    Returns:
        list: Question List
    
    '''
    if update:
        update_list_file(list_file, record_file, url, cookie_file)
    
    question_list = []
    with open(list_file, 'r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        question_list = list(csv_reader)
    
    return question_list

def search_question_from_list(question_id, question_list):
    '''Get a question by its ID from question list.

    Args:
        question_id (int): ID of the question.
        question_list (list): List of questions.

    Returns:
        dict: The specific question; if not exist, return an empty dict
    
    '''
    # Find the exact question
    current_id = question_id - 1
    while int(question_list[current_id]['frontend_question_id']) < question_id:
        current_id += 1
    while int(question_list[current_id]['frontend_question_id']) > question_id:
        current_id -= 1

    # Test if question id matches
    if int(question_list[current_id]['frontend_question_id']) == question_id:
        return question_list[current_id]
    else:
        return {}

def create_solution_file(question, target_dir, template_file):
    '''Create solution file for a question.

    Args:
        question (dict): Attributes of the question.
        template_file (str): File name of the file used to create solution.

    Returns:
        str: File name of the solution file
    
    '''

    question_id = question['question_id']
    question_title = question['question__title']
    question_title_slug = question['question__title_slug']

    solution_file_name = str(question_id) + '-' + question_title_slug + '.py'
    final_file_name = os.path.join(target_dir, solution_file_name)
    with open(final_file_name, 'w') as sln_file:
        sln_file.write('# ' + question_id + '. ' + question_title +'\n\n')
        sln_file.writelines(template_file)
    return final_file_name


if __name__ == '__main__':
    main()