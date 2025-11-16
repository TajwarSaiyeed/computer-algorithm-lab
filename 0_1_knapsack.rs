use std::io::{self, BufRead};

fn knapsack(n: i32, weights: &[i32], values: &[i32], total_w: i32) -> i32 {
    if n < 0 || total_w == 0 {
        return 0;
    }

    let idx = n as usize;
    
    if weights[idx] <= total_w {
        let selected = knapsack(n - 1, weights, values, total_w - weights[idx]) + values[idx];
        let not_selected = knapsack(n - 1, weights, values, total_w);
        return selected.max(not_selected);
    } else {
        return knapsack(n - 1, weights, values, total_w);
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let n: i32 = lines.next()
        .unwrap()
        .unwrap()
        .trim()
        .parse()
        .unwrap();

    let weights: Vec<i32> = lines.next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let values: Vec<i32> = lines.next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let total_w: i32 = lines.next()
        .unwrap()
        .unwrap()
        .trim()
        .parse()
        .unwrap();

    let result = knapsack(n - 1, &weights, &values, total_w);
    println!("{}", result);
}