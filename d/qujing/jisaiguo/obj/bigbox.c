inherit ITEM;

void create()
{
        set_name("��ľ����", ({ "big box", "box"}));
        set_weight(40000);
        if( clonep() ) {
                set("unit", "��");
                set("long","һ��װ���Ĵ�ľ���ӣ��������൱���ء�\n");
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        if( environment() != environment(this_player())
        ||      !id(arg) ) return 0;

        if( (int)this_player()->query_stat("kee") < 10 ) {
                write("������������ˣ�ЪЪ�ٰ�ɣ�\n");
                return 1;
        }

        if( move(this_player()) ) {
                message_vision("$N���������µ�" + name()+"����������\n", 
this_player());
                this_player()->consume_stat("kee", 10);
                return 1;
        }
}

