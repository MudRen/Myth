//jinmu.c
inherit ITEM;

void init();
int do_see();

void init()
{
        add_action("do_see","see");
}

void create()
{
        set_name( "���׽�ĸ", ({ "jin mu","jin","mu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�麣�׽�ĸ�����������ƵĹ⣬�����������ģ�\n"
                    "�ƺ�����������ľ��ò��ϡ�\n");
                set("value", 0);
                set("material", "iron");
              }
}



int do_see()
{
        write("xixi");
        return(0);
}

