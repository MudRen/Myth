#include <ansi.h>
#include <room.h>

inherit ROOM;
int opp=0;
int dm=100000000;
void create (int level,int num)
{
  set ("short", HIG "ħ����ʯ��" NOR);
  set ("long", @LONG
һ�Ⱦ޴��ʯ������ǰ��̧ͷԶ����ȥ����ħ����εȻ������ɽͷ��
����Ҫ�����ʯ�����ķѹ���ġ�
LONG);
     level=10; num=random(2)+1;
    set("exits", ([

            "northup" : __DIR__"shan1",
                                 ]));
        set("level",level);//�Լ������趨��
        set("alternative_die",1);
        set("mofengroom",1);
        set("npc_npc",num);//�Լ������趨��
        set("objects",([
        "/d/quest/mofeng/npc/tudi" : 1,

                 ]));

  setup();


}

void init()
{

    add_action("do_break", "break");

}
void do_check(object who)
{
        object env,*inv;
        int i,count,dm,fa;
        env=this_object();
        inv = all_inventory(env);
        if (env->query("open_time") && env->query("open_time")+3 > time())
               {
          message_vision("$N������������һ�£�ʯ����˿δ����\n" +NOR,who);
          return;}

       env->set("open_time",time());

       fa=0;count=0;
       for (i=0;i<sizeof(inv);i++)
       {
       if (!userp(inv[i])) continue;
       if (inv[i]->query_temp("allow_tudi"))
        {
        count ++;
        fa +=inv[i]->query("force_factor");
        inv[i]->receive_wound("kee", 100*(random(3)+2));
        inv[i]->receive_damage("sen",100*(random(3)+2));
        if (inv[i]->query("force")>300) inv[i]->add("force",300);
        if (inv[i]->query("mana")>300) inv[i]->add("mana",300);
      message_vision("$N�úܴ���������һ�£��۵İ�����ʯ������ƶ��˼��£���\n" +NOR,who);

        }
       }

       dm -=(count-3)*fa;
       if (dm < 0)
       { message("system",HIG+"��ʱ����񺿣��ض�ɽҡ��ħ����֮�����ڴ��ˣ�\n" +NOR,users());
       env->set("opened",1);

       dm=100000000;
       }

}

int do_break(string arg)
{
       object who ;
         who=this_player();
       if (this_object()->query("opened"))
          {
          tell_object(who,"���ع���˵��ʯ�Ų��ǿ���\n");
          return 1;
          }

       if (!who->query_temp("allow_tudi"))
        {
        tell_object(who,"���ع���˵���㼱ʲô�������Ҫ��ȥ��\n");
        return 1;
        }
       if (arg!="door")
       {
       tell_object(who,"���ع���˵������ʲô��\n");
        return 1;
        }
       if (opp==0)
       {
       message("system",HIG+who->name()+"��ͼ��ħ����֮�ţ�������ף$nһ����\n" +NOR,users(),who);
       opp ++;

       }
               do_check(who);

       return 1;

}


void alternative_die(object who)
{
    object killer,corpse;
    killer = who->query_temp("last_damage_from");

    if (userp(who))
    {
        message_vision("$N���ˡ�\n",who);
        who->set("kee",100);
        who->set("sen",100);
        if (who->query("eff_kee") < 10)
            who->set("eff_kee",100);
        if (who->query("eff_sen") < 10)
            who->set("eff_sen",100);


    }
    else
    {
        if (objectp(corpse = CHAR_D->make_corpse(who, killer)))
            corpse->move(this_object());
        message_vision("$N���ˡ�\n",who);

        destruct(who);
    }
}



int valid_leave (object who, string dir)
{
  object where = this_object ();
  object obj = present ("tudi",where);


 if (dir=="northup")
        {
  if (!who->query_temp("allow_tudi") )
    return notify_fail ( obj->name()+"˵����"+who->name()+"!�˵�Σ�գ���ذɣ�\n");
  if (!where->query("opened"))
      return notify_fail("ʯ��δ���������ȥ��\n");
        }
  return ::valid_leave (who, dir);
}

