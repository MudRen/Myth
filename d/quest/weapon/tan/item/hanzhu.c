//yuzhu.c
inherit ITEM;
void create()
{
        set_name( "��˿����", ({ "han zhu","zhu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����˿����ͨ�徧Ө΢΢�����̹⾧Ө��͸������ˮ��\n��ɵģ�����������������ƺ�����������ľ��ò��ϡ�\n");
                set("value", 0);
                set("material", "bamboo");
              }
}

