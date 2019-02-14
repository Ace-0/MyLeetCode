import requests
import json
import os


def main():
    target_dir = os.getcwd()
    tool_dir = 'tools'
    cookie_file = os.path.join(target_dir, tool_dir, 'cookie.txt')
    record_file = os.path.join(target_dir, tool_dir, 'record.json')
    target_file = os.path.join(target_dir, 'README.md')
    leetcode_url = 'https://leetcode.com/api/problems/algorithms/'

    cookie = load_cookie(cookie_file)
    record_json = get_record_and_save(record_file, leetcode_url, cookie)
    # del record_json['stat_status_pairs']

    generate_record_md(record_json, target_file)

def load_cookie(cookie_file):
    cookie = ''
    with open(cookie_file, 'r') as f:
        cookie = f.read()
    return cookie

def get_record_and_save(record_file, leetcode_url, cookie):
    headers = {
        'cookie': cookie,
    }
    html = requests.get(leetcode_url, headers=headers)
    json_object = json.loads(html.content.decode('utf-8'))

    with open(record_file, 'w') as f:
        f.write(str(json_object))

    return json_object

def generate_record_md(record_json, target_file):
    with open(target_file, 'w') as f:
        # title
        title = 'My LeetCode Record'
        f.write('# ' + title + '\n\n')

        # progress bar
        num_total = record_json['num_total']
        num_solved = record_json['num_solved']
        progress_total = num_solved / num_total
        max_length = 60
        length_solved = round(progress_total * max_length)
        length_unsolved = round((1 - progress_total) * max_length)
        f.write('```shell\n{ ' + ('%' * length_solved) + ('-' * length_unsolved) + '} ')
        f.write(str(round(progress_total * 100, 1)) + '%')
        f.writelines('   ' + str(num_solved) + '/' + str(num_total) + '\n```\n\n')

        # # difficulty
        # ac_easy = record_json['ac_easy']
        # ac_mediums = record_json['ac_mediums']
        # ac_hard = record_json['ac_hard']
        # f.write()

        # questions list
        questions_list = record_json['stat_status_pairs']
        questions_list.sort(key=lambda p: p['stat']['question_id'])

        f.write('ID | Title | Difficulty | Status\n-|-|-|-\n')
        str_list = []
        for ques in questions_list:
            frontend_question_id = ques['stat']['frontend_question_id']
            question__title = ques['stat']['question__title']
            difficulty = ques['difficulty']
            status = ques['status']

            ques_str = str(frontend_question_id) + ' | ' + question__title + ' | '
            if difficulty['level'] == 1:
                ques_str += 'Easy'
            elif difficulty['level'] == 2:
                ques_str += 'Medium'
            elif difficulty['level'] == 3:
                ques_str += 'Hard'
            else:
                ques_str += 'Unknown'
            ques_str += ' | Accepted\n' if status == 'ac' else ' | \n'

            str_list.append(ques_str)
        f.writelines(str_list)



if __name__ == "__main__":
    main()
