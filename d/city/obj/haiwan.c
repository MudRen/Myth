// haiwan
// mon 6/18/98

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ɴ���", ({"hai wan", "wan", "bowl"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ʢ���׿�ˮ����ɴ��롣\n");
		set("unit", "��");
		set("max_liquid", 20);
		set("no_get","������ҺȲ����𣿣���\n");
		set("drink_msg", "$N����$n��ཹ�ཱུع��¼����$l��\n");
	}

	set("liquid", ([
		"type": "water",
		"name": "�׿�ˮ",
		"remaining": 20,
	]));
}

int do_drink(string arg)
{
    mapping table;

    if( !this_object()->id(arg) ) return 0;

    if(!environment(this_object())->in_table(this_player())) {
	write("��������������ɳ��Ǻȵģ���\n");
	return 1;
    }
    
    table=environment(this_object())->query_TABLE();
    if(undefinedp(table["cond"]) ||
	    table["cond"]=="����" ||
	    table["cond"]=="�ȷ���") {
	write("����û��ʼ�أ��ȹ�ˮ��\n");
	return 1;
    }

    set("liquid/remaining",20);
    return ::do_drink(arg);
}
