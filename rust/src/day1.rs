use std::fs::{self, File};
use std::io::{self, BufRead};
use std::path::Path;

pub fn openday1input() -> Vec<i32> {
    let lines = fs::read_to_string("./inputdata/day1.txt").expect("file not found")
                         .lines()
                         .map(|l| l.parse::<i32>().unwrap()).collect();

    lines
}

pub fn day1part1() -> i32 {
    let mut increase_count = 0;
    let nums = openday1input();
    let numslength = nums.len();

    for n in 0..numslength-1 {
        let prev = nums[n];
        let next = nums[n+1];

        if prev < next {
            increase_count = increase_count + 1;
        }
    }

    increase_count
}

pub fn day1part2() -> i32 {
    let mut increase_count = 0;
    let nums = openday1input();

    let numslength = nums.len();

    let mut windows: Vec<(usize, (i32, i32, i32))> = vec![];

    for n in 0..numslength-2 {
        let one = nums[n];
        let two = nums[n+1];
        let three = nums[n+2];

        windows.push((n, (one, two, three)));
        //
        // if prev < next {
        //     increase_count = increase_count + 1;
        // }
    }

    for s in 0..windows.len()-1 {
        let prevwin = windows[s];
        let nextwin = windows[s+1];

        let prevsum = prevwin.1.0 + prevwin.1.1 + prevwin.1.2;
        let nextsum = nextwin.1.0 + nextwin.1.1 + nextwin.1.2;

        if prevsum < nextsum {
            increase_count = increase_count + 1;
        }
    }

    increase_count
}