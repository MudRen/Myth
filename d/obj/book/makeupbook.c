//Cracked by Roath


#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;
void create() {
        set_name(HIM"̴����"NOR, ({"tanxiang shan","shan","book"}));
    set("long","һ�������˱ǵ�̴���ȣ���������������д����һ�ʾ����ӬͷС����");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
//              set("no_sell",1);
        set("material", "paper");
        set("skill", ([
                        "name": "makeup",
                        "sen_cost": 15,
                        "difficulty": 20,
                        "max_skill": 150,
]) );
        }
}
