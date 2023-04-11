#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import json


def load_questions(level):

    with open('questions_data.json', 'r') as f:
        data = ''.join(f.readlines())

    questions = json.loads(data)[level]

    return questions


def genmd(questions, level):

    if level == 'pj':
        print('## Modalidade Programação - Nível Júnior\n')

    for year in questions:
        print(f'### {year}\n')

        for phase in sorted(questions[year]):
            print(f'#### Fase {phase}\n')

            for question in questions[year][phase]:
                print(f'- {question["nome_completo"]}: [OBI]({question["url_obi"]})')

            print()


if __name__ == '__main__':


    if len(sys.argv) < 2:
        print('Usage: python3 genmd.py {pj | p1 | p1 | pu}')
        sys.exit(-1)

    level = sys.argv[1]

    if level not in [ 'p1', 'p2', 'pj', 'pu' ]:
        print(f'Invalid level: {level}')
        sys.exit(-2)

    questions = load_questions(level)

    genmd(questions, level)
