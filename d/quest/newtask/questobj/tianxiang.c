#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�������צ��", ({ "tianxiang" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "��������ɢ���书��ѧ���ؼ���\n");
          }

    setup();
}
