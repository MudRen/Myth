// deng.c

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>

void create()
{
        set_name(HIY"������"NOR, ({"baolian deng", "deng"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "յ");
                set("long",
HIR"һյ��Ө��͸�ĵƣ���������ȼ��ʱ��ᷢ�������â��ʹ�˾��������������\n"NOR);
                set("value", 0);
                set("material", "crystal");
                set("no_drop", "���������������ⶪ����\n");
                set("no_give", "�Լ����Űɣ� \n");
                set("no_get", "��ʲô�������񣿼������Ķ�û���ڿ죡 \n");
                set("no_put",1);
        }

        setup();
}

