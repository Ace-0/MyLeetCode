import argparse
import csv
import os


def main():
    target_dir = os.getcwd()
    src_dir = 'src'
    tool_dir = 'tools'
    leetcode_list_file = os.path.join(target_dir, tool_dir, 'problem_list.csv')

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

    args = parser.parse_args()

    question_list = get_question_list(leetcode_list_file)

    question = search_question_from_list(args.id, question_list)

    new_file_name = create_solution_file(question, os.path.join(target_dir, src_dir), args.template)

    print('===============================================================')
    print('|')
    print('| Successfully create', new_file_name)
    print('|')
    print('===============================================================')


def get_question_list(list_file):
    with open(list_file, 'r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        question_list = list(csv_reader)
    
    return question_list


def search_question_from_list(question_id, question_list):
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
    question_id = question['question_id']
    question_title = question['question__title']
    question_title_slug = question['question__title_slug']

    solution_file_name = str(question_id) + '-' + question_title_slug + '.py'
    final_file_name = os.path.join(target_dir, solution_file_name)
    with open(final_file_name, 'w') as sln_file:
        sln_file.write('# ' + question_id + '. ' + question_title + '\n\n\n')
        sln_file.writelines(template_file)
    return final_file_name


if __name__ == '__main__':
    main()