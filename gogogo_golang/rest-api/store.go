package main

import "database/sql"

type Store interface {
	CreateUser() error
	CreateTask(t *Task) (*Task, error)
}

type Storage struct {
	db *sql.DB
}

func NewStore(db *sql.DB) *Storage {
	return &Storage{
		db: db,
	}
}

func (s *Storage) CreateUser() error {
	return nil
}

// func (s *Storage) CreateTask(t *Task) (*Task, error) {

// }
