inherit BULLETIN_BOARD;
void create()
#include <ansi.h>
{
  set_name(HIR"ɱ����԰���԰�"NOR, ({ "board" }) );
  set("location", "/d/pkdao/pkdao.c");
  set("board_id", "pkboard");
  set("long", "ɱ���Ƕ��Լ���ɱ¾����ʮ���Ժ�����ϲ����������\n" );
  setup();
  set("capacity", 80);
  replace_program(BULLETIN_BOARD);
}
