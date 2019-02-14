import json
import os


def main():
    record_file = 'F:\\LeetCode\\tools\\my_record.json'
    target_dir = os.path.dirname(os.getcwd())
    target_file = 'F:\\LeetCode\\README.md'

    record_json = load_record_file(record_file)
    # del record_json['stat_status_pairs']

    generate_record_md(record_json, target_dir, target_file)

def load_record_file(record_file):
    with open(record_file, 'r') as f:
        json_object = json.load(f)

        return json_object

def generate_record_md(record_json, target_dir, target_file):
    final_file_name = os.path.join(target_dir, target_file)
    with open(final_file_name, 'w') as f:
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
        f.write(' ' + str(round(progress_total * 100)) + '%')
        f.writelines('   ' + str(num_solved) + ' / ' + str(num_total) + '\n```\n\n')

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
