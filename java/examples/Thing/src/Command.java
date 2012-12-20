package com.slashthings.common;
abstract class Command {
	public abstract Command create();
	public abstract void run();
}
