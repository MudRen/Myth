inherit BULLETIN_BOARD;

void create()
{
  set_name("�������Ա�", ({"board"}) );
  set("location", "/d/kaifeng/tieta");
  set("board_id", "kaifeng_b");
  set("capacity", 100);
  set("long", "������һ�����Աڣ�����д�������ԡ�\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

