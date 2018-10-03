module.exports = {
  entry: './src/index.re',
  output: {
    path: __dirname + '/public',
    filename: 'bundle.js'
  },
  mode: "development",
  module: {
    rules: [
      // Set up Reason and OCaml files to use the loader
      {
        test: /\.(re|rei|ml|mli)$/,
        exclude: __dirname+'/node_modules/',
        use: 'bs-loader'
      },
      {
        test: /\.js$/,
        exclude: __dirname+'/node_modules/',
        use: [{
          loader: 'babel-loader',
          options: {
            presets: [
              '@babel/preset-env',
              '@babel/preset-react'
            ]
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
