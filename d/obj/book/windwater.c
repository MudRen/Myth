//Cracked by Roath
// nowords.c
//cglaem...12/16/96.

inherit ITEM;

void init();
void tear();

void create()
{
        set_name("����ˮ��", ({"book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ���������С���ӡ����滮��һ����֮���ͼ����\n");
        set("material", "paper");
        set("value", 100);
        set("skill", ([
                        "name": "spells",
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill": 20,
]) );
        }
	setup();
}


