//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("����ħɽ�ľ���", ({"fumo book", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long", "һ���Ͳ�Ƥ��С���ӣ���һ��ȴ��֪ʲôԭ�򱻳�����\n");
        set("material", "paper");
        set("value", 100000); 
        set("skill", ([
                        "name": "force",
                        "exp_required": 200,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 30,
]) );
        }
}

