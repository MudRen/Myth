// shuidai.c ˯��

inherit ITEM;

void create()
{
        set_name("˯��", ({"shui dai", "sleepbag", "dai"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������֯��˯�����ǳ���Զ�бر�֮��\n");
                set("unit", "��");
                 set("value", 5000);
        }
}

