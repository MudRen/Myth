
inherit ITEM;

void create()
{
        set_name("������", ({ "wuming hua", "wuming", "hua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������С����������С��ȴʮ��������\n");
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$N��" + name() + "�ӽ�������¾�������ȥ��\n", me);
        destruct(this_object());
        return 1;
}


