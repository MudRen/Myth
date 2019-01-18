// Room: /d/wiz/guest.c    snowcat
// #include <command.h> 

inherit ROOM;

int clean_up();

void create()
{
  set("short", "ӭ����");
  set("long", @LONG

�Բ������ĵ�ַ�ڱ�վ��������������ƻ��ˣ�Ϊ�˱�֤
���������ڵĴ��������ܹ�������Ϸ�����ǲ��ò�����
����������ɣе�ַ�����ߡ������ڿ����Ժ򣬱�վ����ʦ
�ᾡ��������Ӧ����ͬʱ���������Ķ������ļ�(help)��
��Ϸ����(story)��

LONG
);

  set("valid_startroom", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_net_dead",1); 
  set("objects", ([
    __DIR__"npc/guest":1,
  ]));
       seteuid(getuid());
  setup();
  (load_object("/obj/board/guestroom_b"))->move(this_object());
}

int nb_guests (object where)
{
  int i = 0;
  int j = 0;
  object *obs = all_inventory(where);

  j = sizeof(obs);
  while (j--)
  {
    if (userp(obs[j]) && !wizardp(obs[j]))
      i++;
  } 
  return i;
}

void init()
{  
  object who = this_player(); 
  object where = this_object();

  if (!wizardp(who)&&userp(who))
  {
    if (who->query("banned_approved")==1)
    {
      tell_object (who,"��ӭ���������������磡\n");
      who->move(who->query("startroom"));
      MONITOR_D->report_system_object_msg (who,  
        "�ɱ�����IP���룬�ѱ���׼ֱ�����������硣"); 
      return; 
    }
    who->set("startroom","/d/wiz/guest");
    who->save();
    add_action("block_cmd","",1);  
    MONITOR_D->report_system_object_msg (who,  
      "��IP�������ֱ�����������ӭ����(/d/wiz/guest.c)��");  
    if (nb_guests(where) > 10)
    {
      tell_object ("�Բ���ӭ���������̫�࣬���´�������\n",who);
      who->command_function("quit");
      return;
    }
  }
  else
  {
//    call_out ("inform_wiz",1,who);
//    add_action ("do_approve", "approve");
  }
}

int clean_up()
{      //special for this room. no clean_up.

       return 0;
}

void inform_wiz (object who)
{
  tell_object (who,"�����ʹ��approve����׼��ҽ������μ����硣\n");
}

int block_cmd()
{
           object link_ob,me;
  string verb = query_verb();
              me=this_player();
  if (verb=="say") return 0; 
  if (verb=="help") return 0;
  if (verb=="who") return 0;
  if (verb=="look") return 0;
  if (verb=="story") return 0;
  if (verb=="quit") {
//
        if(this_player()->query("combat_exp")<10000 || !wizardp(me))
         {
      link_ob = me->query_temp("link_ob");
        if ( link_ob )
//       rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
//        rm( me->query_save_file() + __SAVE_EXTENSION__ );
//
//
              tell_object (this_player(),"�ټ���\n");
       }
//     CHANNEL_D->do_channel(this_object(), "sys",
//        me->name() + "("+me->query("id")+")��ϵͳǿ���뿪����Ϸ������� "+reclaim_objects()+" ��������");
 //     me->command_function("quit");
             return 0;
        }
  if (verb=="post") return 0;
  return 1;
}

int do_approve (string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();

  if (! arg)
    return notify_fail ("��׼˭��\n");
  who = present (arg);
  if (who == me)
    return notify_fail ("��׼���Լ���\n");
  tell_object (me,"����׼"+who->query("name")+"�������������磡\n");
  tell_object (who,"��ӭ���������������磡\n");
  who->set("banned_approved",1);
  who->set("startroom","/d/city/kezhan");
  who->move("/d/city/kezhan");
  who->save();
  return 1;
}
