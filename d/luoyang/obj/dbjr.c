#include <ansi.h>
#include <armor.h>

inherit HEAD;
string do_wear();
string do_remove();

void create()
{
        set_name(HIM "��������" NOR, ({ "diebei jiaren", "jiaren" ,"hua"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "����һ��������ɫ�ʵص������ˣ��˻��������伫Ʒ�еļ�Ʒ��\n" NOR);
                set("value", 1000000);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 8);
                set("wear_msg", (: do_wear :));
                set("remove_msg",(: do_remove :));
        }
        setup();
}


string do_wear()
{
        object me;

        me = this_player();

        message_vision(HIY "$N��ʼ��"HIM"��������"HIY"������Լ�\n"
                    HIY "����"HIM"��������"HIY"��,$N��ʱɢ�������˵�������\n" NOR,me);
}

string do_remove()
{
        object me;
        me = this_player();
                message_vision(HIY "$N��"HIM"��������"HIY"ժ��������$N�����ټ���\n",me);
}



