// r-rose.c ��õ��

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(RED "��õ��" NOR, ({ "red rose", "rose", "meigui" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED "һ������͵ĺ�õ�壬������һ˿���顣\n" NOR);
                set("value", 5000);
                set("wear_msg", HIM "$N����һЦ���ѻ������ڷ����ϣ�������Ů�·���\n" NOR);
                set("remove_msg", HIM "$N�ѻ����ӷ���ȡ�£����������ţ����ػ��С�\n" NOR);
                set("armor_prop/armor", 50);
        }
        setup();
}

void init()
{ 
  object ob;
  ob=this_object();
  add_action("come_life","wen");
  add_action("come_life","smell");     
}
        
int come_life(string arg)
{
    object me;
    me=this_player();

    if(!arg) return 0;
    if(arg == "rose" || arg == "red rose" || arg == "meigui") 
      {
// 41          me->reincarnate();  
        me->set("long", @LONG

                         __  _-==-=_,-.
                        /--`' \_@-@.--<
                       `--'\ \   <___/.
                            \ \\   " /
                              >=\\_/`
                  ____       /= |  \_/|
                _'    `\   _/=== \___/
                 `___/ //\./=/~\====\
                    \   // /   | ===:
                     |  ._/_,__|_ ==:        __
                      \/    \\ \\`--|       / \\
                       |    _     \\:      /==:-\
                       `.__' `-____/       |--|==:
                          \    \ ===\      :==:`-'
                          _>    \ ===\    /==/
                         /==\   |  ===\__/--/
                        <=== \  /  ====\ \\/
                        _`--  \/  === \/--'
                       |       \ ==== |
                        `------/`--' /
                               \___-'

LONG);             
/*
        me->set("env/msg_dest", HIR"��ϵͳ������ָ�"HIG"��ͨ���� $n(Zen) "HIR"�뿪��Ϸ�ˡ�"NOR);
        me->set("env/msg_home", "�������$NͶƱ���Լ�������Ƶ����$N������Ƶ�������ˣ�");
        me->set("env/msg_mout", NOR"$N����һ����"HIY"�ƽ�"NOR"��");
        me->set("env/msg_min", NOR"$N����һǧ��"HIY"�ƽ�"NOR"��");
        me->set("env/msg_clone", HIR"��ϵͳ�����߾��飺"HIG"��ͨ���� $n(Zen) "HIR"�� "HIG"255.255.255.255 "HIR"�������߽��롣"NOR);
*/

        message_vision(RED"$N��Сָ������ס��õ�壬����������������š�\n"NOR,me);
        tell_object(me, HIY "�š�����������������ѽ��\n" NOR);
      }    
    return 1;
}

