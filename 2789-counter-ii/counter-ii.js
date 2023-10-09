/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
     let counter={
         x:init,
         temp:init,
         increment(){
             return ++(this.x);
         },
         reset(){
             this.x=this.temp
             return this.x;
         },
         decrement(){
             return --(this.x);
         }
    };
    return counter;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */