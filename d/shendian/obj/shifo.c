inherit ITEM;
void create()
{
        set_name("ʯ��", ({"shifo", "fo"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ��ʯ�ƵĹŷ�");
                set("base_unit", "��");
                set("base_weight", 0);
                set("no_sell","��ô���Ķ�������ɲ����գ�" );
                set("no_give","��ô���Ķ��������˲���ð�"); 
        }
        setup();
}

