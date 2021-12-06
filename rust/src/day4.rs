use std::fs::{self, File};
use std::io::{self, BufRead, Lines};
use std::path::Path;

struct BoardSpace {
    marked: bool,
    val: u8
}

impl BoardSpace {
    fn new(line: &str, val: u8) -> Self {
        Self {
            marked: false,
            val: val
        }
    }

    fn setMarked(&mut self, marked: bool) {
        self.marked = marked;
    }
}


struct Board {
    index: usize,
    spaces: Vec<BoardSpace>,
}

impl Board {
    fn newBoard(index: usize) -> Self {

        Self {
            index: index,
            spaces: vec![]
        }
    }

    fn addRow(&mut self, row: &str) {
        let splitted = row.split(' ');

        for num in splitted {
            println!("{} num from addrow", num);
            if (num == "") {
                continue;
            }
            if (num != "\n") {
                self.spaces.push(BoardSpace { val: num.parse::<u8>().unwrap(), marked: false});
            }
        }
    }

    fn checkWin(&self) -> (bool, usize) {

        let (vertWin, index) = self.checkVerticals();
        let (horizWin, index) = self.checkHorizontals();

        (vertWin | horizWin, index)
    }

    fn checkVerticals(&self) -> (bool, usize) {

        for i in 0..5 {
            // spaces[0 + 5*i]
        }

        let column1 = self.spaces[0].marked
            && self.spaces[5].marked
            && self.spaces[10].marked
            && self.spaces[15].marked
            && self.spaces[20].marked;

        let column2 = self.spaces[1].marked
            && self.spaces[6].marked
            && self.spaces[11].marked
            && self.spaces[16].marked
            && self.spaces[21].marked;

        let column3 = self.spaces[2].marked
            && self.spaces[7].marked
            && self.spaces[12].marked
            && self.spaces[17].marked
            && self.spaces[22].marked;

        let column4 = self.spaces[3].marked
            && self.spaces[8].marked
            && self.spaces[13].marked
            && self.spaces[18].marked
            && self.spaces[23].marked;

        let column5 = self.spaces[4].marked
            && self.spaces[9].marked
            && self.spaces[14].marked
            && self.spaces[19].marked
            && self.spaces[24].marked;

        return (column1 | column2 | column3 | column4 | column5, self.index);
    }

    fn checkHorizontals(&self) -> (bool, usize) {

        let row1 = self.spaces[0].marked
            && self.spaces[1].marked
            && self.spaces[2].marked
            && self.spaces[3].marked
            && self.spaces[4].marked;

        let row2 = self.spaces[0+5].marked
            && self.spaces[1+5].marked
            && self.spaces[2+5].marked
            && self.spaces[3+5].marked
            && self.spaces[4+5].marked;

        let row3 = self.spaces[0+10].marked
            && self.spaces[1+10].marked
            && self.spaces[2+10].marked
            && self.spaces[3+10].marked
            && self.spaces[4+10].marked;

        let row4 = self.spaces[0+15].marked
            && self.spaces[1+15].marked
            && self.spaces[2+15].marked
            && self.spaces[3+15].marked
            && self.spaces[4+15].marked;

        let row5 = self.spaces[0+20].marked
            && self.spaces[1+20].marked
            && self.spaces[2+20].marked
            && self.spaces[3+20].marked
            && self.spaces[4+20].marked;

        return (row1 | row2 | row3 | row4 | row5, self.index);
    }

    fn calculateScore(&self) -> i32 {
        let mut sum = 0i32;
        for b in &self.spaces {
            if b.marked == false {
                sum = sum + b.val as i32;
            }
        }
        sum
    }

    fn mark(&mut self, val: u8) {
        //for n in spaces: if n == val, n.setMarked(true)
        for bs in &mut self.spaces {
            if (bs.val == val) {
                bs.setMarked(true);
            }

        }
    }

}

pub fn openday4input<'a>() -> Vec<String> {
    let mut lines = fs::read_to_string("./inputdata/dayfour.txt").expect("file not found")
        .lines().map(|l| String::from(l)).collect();
    lines
}

pub fn day4part1() -> i32 {

    let input = openday4input();
    let randompulls = input[0].split(",");

    let mut boards = vec![];

    for i in 0..100 {
        let inputindex = 2 + (6*i);
        let mut board = Board::newBoard(i);
        board.addRow(&input[inputindex]);
        board.addRow(&input[inputindex+1]);
        board.addRow(&input[inputindex+2]);
        board.addRow(&input[inputindex+3]);
        board.addRow(&input[inputindex+4]);
        println!("{}", inputindex);
        boards.push(board);
    }

    let mut winningpull = 0;
    let mut winningindex = 0;

    'outer: for p in randompulls {
        println!("randompull: {}", p);
        let i = p.parse::<u8>().unwrap();

        for b in &mut boards {
            //println!("Board index: {}", b.index);
            b.mark(i);

            let (win, index) = b.checkWin();
            if win {
                println!("Win! Index: {}", index);
                winningpull = i;
                winningindex = index;
                break 'outer;
            }
        }
    }

    let score = boards[winningindex].calculateScore();
    let finalscore = score * winningpull as i32;

    println!("Score: {} Winning pull: {} Final Score: {} ", score, winningpull, finalscore);

    0
}

pub fn day4part2() -> i32 {

    let input = openday4input();
    let randompulls = input[0].split(",");

    let mut boards = vec![];

    for i in 0..100 {
        let inputindex = 2 + (6*i);
        let mut board = Board::newBoard(i);
        board.addRow(&input[inputindex]);
        board.addRow(&input[inputindex+1]);
        board.addRow(&input[inputindex+2]);
        board.addRow(&input[inputindex+3]);
        board.addRow(&input[inputindex+4]);
        println!("{}", inputindex);
        boards.push(board);
    }

    let mut winningpull = 0;
    let mut winningindex = 0;

    let mut winningboards: Vec<(usize, u8)> = vec![];

    'outer: for p in randompulls {
        println!("randompull: {}", p);
        let i = p.parse::<u8>().unwrap();

        for b in &mut boards {
            //println!("Board index: {}", b.index);
            b.mark(i);
        }
        for b in &mut boards {

            let (win, index) = b.checkWin();
            if win {
                let foo = (index, i);
                if !winningboards.contains(&foo) {
                    winningboards.push((index, i));
                }


                if winningboards.len() == 100 {
                    println!("Last Win! Index: {} Lastpull: {}", index, i);
                    winningpull = i;
                    winningindex = index;

                }
            }
        }
    }

    let score = boards[winningboards[99].0].calculateScore();
    let finalscore = score * winningpull as i32;

    println!("Score: {} Winning pull: {} Final Score: {} ", score, winningpull, finalscore);

    0
}