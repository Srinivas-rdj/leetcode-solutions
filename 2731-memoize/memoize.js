/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const arr=[];
    return function(...args) {
      for(let i=0;i<arr.length;i++){
          if(args.length==2){
              if(args[0]==arr[i][0]&&args[1]==arr[i][1]) return arr[i][2];
          }
          else{
              if(args[0]==arr[i][0]) return arr[i][1];
          }
      }
      let res=fn(...args);
        arr.push([...args,res]);
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */