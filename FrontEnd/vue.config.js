module.exports = {
  devServer: {
    proxy: {
      '/api': {
        target: 'http://localhost:5000'
      },
    },
    port: 8008
  }
}