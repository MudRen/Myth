// rose1.c ��õ��

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(YEL "��õ��" NOR, ({ "yellow rose", "rose", "meigui" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "һ��ѩ���͵Ļ�õ�壬������һ˿���顣\n" NOR);
                set("value", 5000);
                set("wear_msg", HIM "$N����һЦ���ѻ������ڷ����ϣ�������Ů�·���\n" NOR);
                set("remove_msg", HIM "$N�ѻ����ӷ���ȡ�£����������ţ����ػ��С�\n" NOR);
                set("armor_prop/armor", 10);
        }
        setup();
}

void init()
{
  
  add_action("come_life","wen");
  add_action("come_life","smell");

}
        
int come_life(string arg)
{
    object me;
    me=this_player();

    if(!arg) return 0;
    if(arg == "rose" || arg == "red rose" ) 
      {
        me->delete("oyf_fail");        
        message_vision(YEL"$N��Сָ������ס��õ�壬����������������š�\n"NOR,me);
        tell_object(me, HIY "�š�����������������ѽ��\n" NOR);
        message_vision("��õ�彥����ή�ˡ�\n",me);
        destruct(this_object());
      }    
    return 1;
}

