#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("��������", ({ "du jing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�������˶�����һ������������ʱ�������ݵõ�����������ʩ������ں��棬ʹ�����������ӷḻ��\n");
          }

    setup();
}
