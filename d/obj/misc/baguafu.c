#include <ansi.h>
inherit ITEM;
void init();
void create()
{
  set_name("���Է�", ({"bagua fu", "fu",}));
  set_weight(100);
  set("unit", "��");
  set("value", 0);
        setup();
}

void init()
{
  add_action("do_direct","direct");
}
int do_direct (string arg)
{
  object me = this_player();
  if (!arg) return notify_fail("�÷���direct <direction>\n");
  write ("��������ڰ��Է���д�� "HIR+arg+ NOR" ��\n");
  set("dir",arg);
  return 1;
}
