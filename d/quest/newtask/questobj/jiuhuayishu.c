#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���Ż����顿", ({ "jiuhua yishu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�伮���Ż��������������������ڼ��书����֮�����߳��ơ���Ѩ��Ѩ֮���������ơ�����󷨡����ʮ�˽������Ĵ���ơ���հ����񹦵������书��\n");
          }

    setup();
}
