//Cracked by Roath
// girlbook.c

inherit ITEM;

void create()
{
        set_name("��Ů������", ({"book","nu","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ��С���ӡ����Ķ��������ĵ¡�����Ȼ��һ��ϲ��������ʶ��Ҳ�Ǻõġ�\n");
        set("material", "paper");
        set("value", 1000);
        set("skill", ([
                        "name": "literate",
                        "exp_required": 1000,
                        "sen_cost": 30,
                        "difficulty": 30,
                        "max_skill": 50,
]) );
        }
}

