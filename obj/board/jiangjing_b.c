inherit BULLETIN_BOARD;

void create()
{
  set_name("������", ({"board"}) );
  set("location", "/d/qujing/wuzhuang/jiangjing");
  set("board_id", "jiangjing_b");
  set("capacity", 100);
  set("long", "һ�鹩��ׯ�۵��ӽ����۷������԰档\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

