//Cracked by Roath

inherit ITEM;

void create()
{
        set_name("���", ({"qiu yin"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","һֻ�����������򾣬������һ�ţ��Ѿ�û��ʲô�������ˡ�\n");
        set("unit", "��");
        set("value", 0);
	set("no_sell", 1);
        }
        setup();
}


