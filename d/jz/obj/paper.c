//Cracked by Roath

inherit ITEM;
void create()
{
        set_name("״ֽ", ({"zhuang zhi", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��״ֽ���������������д��һЩ������\n");
                set("material", "paper");
        }
}
