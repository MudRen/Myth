//���Ӻ�
//by dewbaby
 inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
  set_name(HIY"��"HIC"��"HIG"��"HIW"ӭ�ͱ�"NOR,({"board"}));
      set("location","/u/dewbaby/wangxian/minghu1");
      set("board_id","minghu_b");
      set("long",
         HIC"�������ϵ�ӭ�ͱ�����������Ŵ������ĵ������¡�\n"NOR);
    setup();
    set("capacity",500);
    replace_program(BULLETIN_BOARD);
}

