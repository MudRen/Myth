// jinchuang.c ��ҩ

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("������", ({"dieda wan", "wan", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("unit", "Щ");
                set("long", "����һ�����˵ĵ���ҩ��\n");
                set("value", 1500);
				set("drug_type", "��ҩ");
        }
    set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
else {
object me = this_player();
string str;
int i = me->query_skill(str,1);
me->set_skill(str,i+1);
           add_amount(-1);
                return 1;
        }
}

