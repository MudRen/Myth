#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM "̴����" NOR , ({"tanxiang shan", "shan"}));
        set_weight(600);
        set("no_give","��ô���ı��������������ˣ�\n");
        set("no_drop","��ô�õı��������˶��ϧѽ��\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������˱ǵ�̴���ȣ���������������д����һ�ʾ����ӬͷС����\n");
        set("material", "paper");
        set("skill", ([
                        "name": "makeup",
                        "exp_required": 5000,
                        "sen_cost": 10,
                        "difficulty": 25,
                        "max_skill": 150,
]) );
        }
}
