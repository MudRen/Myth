
// Joy  06/26/98
// mm.c  �ͣ��ͣ���

inherit ITEM;
inherit F_FOOD;


void create()
{
        set_name("�ͣ��ͣ���", ({"mms", "chocolate"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ɫ�ģͣ��ͣ����ɿ���������������𡫡� ֻ���ڿڲ������֡�\n");
                set("eat_msg", "$N����һ�ţͣ��ͣ����ɿ������Ž����������Ц��˵�����һ�Ҫ���� \n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 8);
                set("food_supply", 2);
        }
}

