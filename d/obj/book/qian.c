//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("��ǧ���ġ�", ({"qian", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 100);
	set("long",
"һ��������С���ӣ�\n������ƣ������ģ�����ӯ꾣��ǳ����ţ�\n��������\n");
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        //"exp_required": 1000,
                        "sen_cost": 25,
                        "difficulty": 30,
                        "max_skill": 50,
]) );
        }
}

