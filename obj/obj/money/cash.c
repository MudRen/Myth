// thousand.c

inherit MONEY;

void create()
{
        set_name("һǧ����Ʊ", ({"cash", "thousand-cash", "cash_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "cash");
                set("long", "һ�����ֵһǧ�����ӵ���Ʊ��\n");
                set("unit", "��");
                set("base_value", 100000);
                set("base_unit", "��");
                set("base_weight", 3);
                set("material", "paper");
        }
        set_amount(1);
}


