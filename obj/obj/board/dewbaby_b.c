    //�����޻�
    //���θ������԰�

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
  set_name(HIY"��"HIC"��"HIG"��"HIW"��"NOR,({"board"}));
      set("location","/u/dewbaby/workroom");
      set("board_id","dewbaby_b");
      set("long",
         HIW"���ε�˽�����԰壬��ʲô��������ԡ�\n"NOR);
    setup();
    set("capacity",100);
    replace_program(BULLETIN_BOARD);
}
