FROM node:8
WORKDIR /home/node/app

EXPOSE 8888

COPY . .

RUN yarn install --force --ignore-engines
CMD yarn build
