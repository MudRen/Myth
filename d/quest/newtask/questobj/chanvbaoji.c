#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���Ů�񹦱�����", ({ "chanv baoji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�书�ؼ�������Ů��������Ůչ�Ӣһ����Ϊ���ӣ�����������а���������ع��񼼡�����ʮ��������޳�һ��������ʽ���»�ɽ���ڡ������񹦱��������ɴ��顣\n");
          }

    setup();
}
