#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���������꾭��", ({ "huanhun jing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�����ŵ�һ��а�����飬�����С����ꡱһ�ڡ�\n");
          }

    setup();
}
