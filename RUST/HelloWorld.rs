fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    // 2D DP table initialized with 0
    let mut dp = vec![vec![0; n]; m];

    dp[0][0] = grid[0][0];

    // Fill first row
    for j in 1..n {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill first column
    for i in 1..m {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill rest of dp
    for i in 1..m {
        for j in 1..n {
            dp[i][j] = grid[i][j] + dp[i - 1][j].min(dp[i][j - 1]);
        }
    }

    dp[m - 1][n - 1]
}

fn main() {
    let grid = vec![
        vec![1, 3, 1],
        vec![1, 5, 1],
        vec![4, 2, 1],
    ];

    println!("Minimum path sum = {}", min_path_sum(grid));
}
