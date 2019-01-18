// mon 1/29/98

inherit NPC_SAVE;

mapping list=([]);
// notified is set as static so that it will not
// be saved or restored.
static string *notified=({});

int do_help(string arg);
void clear_enter(string id);
void allow_enter(string id);
int remain_time(int approve);
void inform_wiz (object who);
int do_clear(string arg);
int do_list();
int do_approve (string arg);
void relay_channel(object ob, string channel, string msg);


void create()
{
        set_name("��ͯ", ({ "xian tong","tong" }));
        set("long", "");
        set("gender", "����");
        set("age", 15);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,20);
        set("combat_exp", 500000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
	
	if( clonep() ) CHANNEL_D->register_relay_channel("sys");
	
	reload("guest_room");
}

void init()
{       
        object ob=this_player();
	string id=ob->query("id");
	object me=this_object();
	mapping new_guest;
	int approve;
	
        ::init();
        
	if(!userp(ob)) return;

        if(wizardp(ob)) {
          add_action("do_approve","approve");
          add_action("do_clear","decline");
          add_action("do_list","list");
          add_action("do_help","help");
          call_out ("inform_wiz",1,ob);
        } else {
          approve=ob->query("banned_approved");

          if(!approve) { //first time enter here.
            approve=time(); //current time.
            if(approve<100) approve=-1;
            //this should not happen, but if happened due to
            //incorrect system clock, then set to -1.
            ob->set("banned_approved",approve);
            ob->set("startroom","/d/wiz/guest");
            ob->save();
          }
          
          if(remain_time(approve)==0) {
            allow_enter(id);
            return; 
          }   
          
          write(ob->query("name")+
            "����Ⱥ���ʦ��׼���������μ����磡\n");
            
          if(approve>0)  
            write("���û����ʦ���ߣ�������"+
              chinese_number(remain_time(approve))+
              "Сʱ���Զ������ɡ�\n");  
              
          write("�����ĵȺ�лл��\n");
             
          if(approve==-1) return;
          
          if(undefinedp(list[id])) {    
            //add this player to list.
            new_guest=(["name":ob->query("name"),
                        "ip":query_ip_name(ob),
                        "time":approve,
                        ]);
            if(list)
              list+=([id:new_guest]);
            else
              list=([id:new_guest]);
              
            notified=({});
            me->save();                              
          }
         
        }
}

int do_help(string arg)
{
  if(arg) return 0;
  
  write("\n");
  write("����������ﴦ����banned_sites������ҵĽ������󣬲�\n");
  write("�����Ŀǰ����ӭ�������Ѿ��˳������ԡ������������\n");
  write("�����ҽ�����ʮ��Сʱ���Զ���׼������Ϸ��\n\n");
  write("approve id      ׼��ָ����ҽ�����Ϸ��(��ʹ����list\n");
  write("                ��Ҳ����)\n");
  write("approve -all    ׼��������������ҽ�����Ϸ��\n");
  write("decline id      ��׼ָ����ҽ�����Ϸ������������\n");
  write("                newbie�������ܱ�purge�����򽫱���\n");
  write("                ����ӭ������ֱ������ʦapproveΪֹ��\n");
  write("decline -all    ͬ�ϣ���׼������������ҽ�����Ϸ��\n");
  write("list            �г��������������е���ҡ�\n");
  write("\n");
  return 1;
}

// optimize the two following function
// mudring Oct/31/2002
//
// clear one player enter xyj.
void clear_enter(string id)
{
  object me=this_object();
  object who;
  int objp=wizardp(this_player());

    who = UPDATE_D->global_find_player(id);

    if (!who)
    {
        if(objp)
            write("û��"+id+"�����һ��ļ�����\n");

        UPDATE_D->global_destruct_player(who);

        if(!undefinedp(list[id]))
        {
            map_delete(list,id);
            me->save();
        } 
        return;
    }

    if (who->query("banned_approved") != 0)
    {
        who->set("banned_approved",-1);
//        who->save(1);
        if(objp)
            tell_object(this_player(),"������׼"+who->query("name")+"�������μ����磡\n");
        if(objp)
            log_file("banned_approve","["+ctime(time())+"]"+
                this_player()->query("id")+" declines "+who->query("id")+
                " to enter.\n");
        else
            log_file("banned_approve","["+ctime(time())+"]"+
                who->query("id")+
                " is declined to enter.\n");
        
    } else {
        if(objp) write("���"+id+"���ڴ���׼֮�С�\n");
    }

    UPDATE_D->global_destruct_player(who, 1);

    if (!undefinedp(list[id]))
    {
        map_delete(list,id);
        me->save();
    } 
}

//allow one player enter xyj.
void allow_enter(string id)
{
    object me=this_object();
    object who;
    int objp=wizardp(this_player());

    who = UPDATE_D->global_find_player(id);

    if (!who)
    {
        if(objp)
            write("û��"+id+"�����һ��ļ�����\n");

        UPDATE_D->global_destruct_player(who);

        if(!undefinedp(list[id]))
        {
            map_delete(list,id);
            me->save();
        } 
        return;
    }

    if (who->query("banned_approved")!=0)
    {
        who->set("banned_approved",1);
        who->set("startroom","/d/city/kezhan");
//        who->save(1);
        if (objp)
            tell_object (this_player(),"����׼"+who->query("name")+"�������μ����磡\n");
        if(objp)
            log_file("banned_approve","["+ctime(time())+"]"+
                this_player()->query("id")+" allows "+who->query("id")+
                " to enter.\n");
        else
            log_file("banned_approve","["+ctime(time())+"]"+
                who->query("id")+
                " is allowed to enter.\n");
    } else {
         if(objp) write("���"+id+"���ڴ���׼֮�С�\n");
    }    

    if (find_player(id))
    {
        who->move("/d/city/kezhan");
        tell_object (who,"��ӭ���������μ����磡\n");
    }

    UPDATE_D->global_destruct_player(who, 1);
  
    if (!undefinedp(list[id]))
    {
        map_delete(list,id);
        me->save();
    } 
}
// the end of optimize
// mudring Oct/31/2002

int remain_time(int approve)
{ 
  int hour=48-(time()-approve)/3600;

  if(approve<0) //i.e., approve==-1
    return approve;  //not auto approve.
  else if(approve==1 || approve==0 || hour<=0)
    return 0; //approved.
  else
    return hour;  //remaining hours to get auto permission.
}  

void inform_wiz (object who)
{
  tell_object (who,who->query("name")+
    "�������ʹ��help���鿴����ָ�\n");
}

//do not auto permission entry of a player.
//this player must be later explicitly "approved" to enter.
int do_clear(string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();
  string *key;
  int size, i;

  if (!arg)
    return notify_fail ("����׼˭��\n");
    
  if(arg=="-all") { //decline all pending players.
    key=keys(list);
    size=sizeof(key);
    if(size>0) {
      for(i=0;i<size;i++)
        clear_enter(key[i]); 
    }
  } else {  //decline only one player. 
    if (arg == me->query("id")) {
      write("����׼���Լ���\n");
      return 1;
    }
    clear_enter(arg);
  }
  
  return 1;
}

//list all pending players in memory.
int do_list()
{
   int i, size;
   string *key;
   
   key=keys(list);
   size=sizeof(key);
   if(size>0) {
     write("�ȴ���׼������Ϸ������У�\n");
     for(i=0;i<size;i++) {
       int j=remain_time(list[key[i]]["time"]);
       
       write(list[key[i]]["name"]+"("+
         key[i]+")��"+
         list[key[i]]["ip"]+
         "���ߣ�");
       if(j>0)
         write("����"+j+"Сʱ���Զ���׼������Ϸ��\n");
       else if(j==0) {//should not happen.           
         write("�Զ���׼������Ϸ��\n");
         allow_enter(key[i]);
       } else //j<0
         write("���뾭��ʦ��׼���ܽ�����Ϸ��\n");
     }
   } else
     write("Ŀǰû�еȴ���׼������Ϸ����ҡ�\n");
     
   return 1;
}

int do_approve (string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();
  string *key;
  int size, i;

  if (!arg)
    return notify_fail ("��׼˭��\n");
    
  if(arg=="-all") { //allow all pending players.
    key=keys(list);
    size=sizeof(key);
    if(size>0) {
      for(i=0;i<size;i++)
        allow_enter(key[i]); 
    }
  } else {  //allow only one player. 
    if (arg == me->query("id")) {
      write("��׼���Լ���\n");
      return 1;
    }
    allow_enter(arg);
  }
  
  return 1;
}

void relay_channel(object ob, string channel, string msg)
{
	string id, wizid;
	object wiz;
	int size;

        size=sizeof(list);
        if(!size) return;
        
	if( !ob || (channel != "sys") ) return;
	
	id=ob->query("id");
	if(id!="logind") return;

	// Don't process our own speech.
	if( ob==this_object() ) return;
	
	if(sscanf(msg,"%*s(%s)��%*s���߽��롣",wizid)!=3) return;
	
	wizid=lower_case(wizid);
	if(!(wiz=find_player(wizid))) return;
	if(!wizardp(wiz)) return;
	
	if(member_array(wizid,notified)==-1) { //not notified yet.
	  //notify login wiz about pending players in the guest room.
	  tell_object(wiz,"������"+chinese_number(size)+
	    "λ�����ӭ�����Ⱥ���׼����������(/d/wiz/guest)\n");
          notified+=({wizid});
        } //each wiz will only be notified once.
}

