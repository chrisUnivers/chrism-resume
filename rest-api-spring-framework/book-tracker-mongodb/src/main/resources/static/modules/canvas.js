function create(id, parent, width, height) {
  // let divWrapper = document.createElement('div');
  let divWrapper = document.createElement('div');
  let canvasElem = document.createElement('canvas');
  parent.appendChild(divWrapper);
  divWrapper.appendChild(canvasElem);

  divWrapper.id = id;
  canvasElem.width = width;
  canvasElem.height = height;

  let ctx = canvasElem.getContext('2d');

  return {
    ctx: ctx,
    id: id
  };
}
  
function createReportList(wrapperId, liParent) {
  // let divWrapper = document.createElement('li');
  // parent.appendChild(divWrapper);
  let list = document.createElement('ul');
  list.id = wrapperId + '-reporter';

  let canvasWrapper = document.createElement('div');
  liParent.appendChild(canvasWrapper);
  canvasWrapper.appendChild(list);

  canvasWrapper.id = wrapperId;

  return list.id;
}

export { create, createReportList };