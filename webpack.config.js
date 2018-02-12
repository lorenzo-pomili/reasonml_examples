module.exports = {
  entry: './src/Main.re',
  output: {
    path: __dirname + '/public',
    filename: 'bundle.js'
  },
  module: {
    rules: [
      // Set up Reason and OCaml files to use the loader
      { test: /\.(re|rei|ml|mli)$/, use: 'bs-loader' },
      {
        test: /\.js$/,
        use: [{
          loader: 'babel-loader',
          options: {
            presets: ['es2015', 'react']
          }
        }]
      }
    ]
  },
  resolve: {
    // Add .re and .ml to the list of extensions webpack recognizes
    extensions: ['.re', '.ml', '.js']
  }
};
