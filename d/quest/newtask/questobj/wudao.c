#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�������", ({ "wudao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�伮���ݴ�Ϊ��Ħ������̫����ע��������������\n");
          }

    setup();
}
