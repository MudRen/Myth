//bb.c
// cocacola
// Ultra ReEdit

#include <room.h>
#include <ansi.h>
inherit ROOM;

int Maxperson,minperson;
int allow_leave,allow_start,startbp=0,stopbp=0;
int Max1,Max2,Max3,Max4,Max5,Max6;
int Realmode=0;
int NowLea=-1,jinhua=0;
string roomname;
object* member,leader,dutang1,dutang2,winner;
object here=this_object();
int is_busy=0;

void do_yao2(object ob, string re1,int getaward,int getscore,string dest);
void do_yao1(object ob, string re,string re1, int getaward,
	int getscore, string dest);
int  getnewzy();
void game_over(int i);
int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
int do_yao();
int getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
void pass_token(int,int);
int startreal();
int stopreal();
int dkickout(string arg);
string look_sign();

int check_member()
{
    int i,j=0;
    if(!member) return 0;
    i=sizeof(member);
    while(i--) {
	if(!member[i]) {
	    member=member[0..(i-1)]+member[(i+1)..];
	    continue;
	}
	if(!interactive(member[i])) continue;
	if(query_idle(member[i])>240) continue;
	if(environment(member[i])!=here) continue;
	j++;
    }
    return j;
}

void create()
{
        Maxperson=12;
	minperson=4;
	allow_leave=1;
	allow_start=0;
	Max1=32;//һ��ĸ���
	Max2=16;
	Max3=8;
	Max4=4;
	Max5=2;
	Max6=1;
	Realmode=0;//ʵ������û�н�Ʒ.
	roomname="���˲�����";
		//** ��ͬ�ķ����в�ͬ������
	set("no_fight","1");
	set("no_magic","1");
	set("short","���˲�����");
	set("long", @LONG
������һ�����ľ��ĵط�����һʯ��������ʯ�ʣ�������һƬ��ɫ�����֣���Լ
�����ŵ��𻨵���ζ�����ű��������������ŵ�СϪ�������в�������������˹�ĸ�
��������΢΢���˸��У���̾һ�����ֵ������ˣ�����
    ��ʱ��ŷ���ʯ���Ͽ���һЩС��(word)������
LONG);

	set("item_desc",(["word":(:look_sign:)]));
  	set("exits",
  	(["south":"/d/city/kezhan",
	  "north":__DIR__"bobing1"]));
	//**����Ӧ��Ϊʵ�ʵĳ���

	set("valid_startroom", 1);
	// This enables players to save this room as their startroom.

	set("no_clean_up",1);
	setup();
	
//        call_other("/obj/board/bobing.c","???");
	//**�����һ�����԰�
}


void init(){
	add_action("fjoin","join");		//���벩��
	add_action("fleave","leave");		//�뿪
	add_action("fjoiner","joiner");		//�鿴������
	add_action("fyao","bp");		//����	
	add_action("fstartbp","startbp");	//��ʼ����
	add_action("fstopbp","stopbp");		//��������
	add_action("startreal","start");	//��ʦ������ʽ��ʼ
	add_action("stopreal","stop");		//��ʦ������������
	add_action("dkickout","kout");	//ǿ��ĳ���˳�����
	add_action("fnextbp","nextbp");		//ǿ������ĳ��.
}

void give_cake(object ob)
{
    object cake;
    
    if(!ob) return;
    cake=new(__DIR__"obj/mooncake");
    message_vision("$N�õ���һ�龫����$n��\n",ob,cake);
    if(!cake->move(ob))
        cake->move(environment(ob));
}

int fstopbp()
  {
  object *play,ob;
//  if(is_busy && !wizardp(this_player())) return 0;
//  if (!wizardp(this_player()))return 0;
  if (startbp==0)return notify_fail("�����Ѿ�������\n");
  play=users();
  tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
       "============\n"+roomname+"�Ĳ���������\n"NOR);
  startbp=0;
  return 1;
  
  }

int fstartbp()
  {
  object *play,ob;

  if (startbp==1) return notify_fail("�����Ѿ���ʼ��\n");  	
  play=users();
  tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
       "============\n"+roomname+"�Ĳ������ڿ�ʼ��\n"NOR);
  startbp=1;
  return 1;
  }

int fnextbp()
 {
 if (wizardp(this_player()))
   {
   if (NowLea<0) return notify_fail("��û���˿�ʼ������\n");
   pass_token(NowLea+1,0);
   return 1;
   }
 else
   {
   return 0;
   } 
 }

int dkickout(string arg)			
  {
  object ob;
  if (!wizardp(this_player()))return 0;
  if(!arg) return notify_fail("��Ҫ��˭��ȥ��\n");
  if (!objectp(ob=present(arg))) return notify_fail("��Ҫ��˭��ȥ��\n");
  if (!query_member(ob)) return notify_fail("���˲�û�в�����\n"); 
  delete_member(ob);
  Maxperson++;
  tell_room(environment(this_player()),HIY+ob->query("name")+"���߳�ȥ��\n"NOR);
}

string look_sign()
{
string restring;
//if (Realmode) {
restring="������"+roomname+"������ڲ��Թ����з�����ʲô©��������ϵ\n"+
"Ultra��Cocacola(larnk@usa.net)����Ϸ��������:\n"+
"  ��Ҫjoin���뵽������Ϸ�С�(��joiner���Կ����Ѿ������������)\n"+
"  ���ֵ��㶪ʱ����bp����Ϳ����ˡ�(���ڻ�û�н�Ʒ��:)\n"+
"  ���뿪ǰҪ����leave��������뿪��\n"+
"  ���⣬����һ�����������Ϸ�Ĺ���(����в��Ի���֮��������ϵUltra\n"+
"��Cocacola)\n"+
"  ������������6�����ӣ���û���ҵ�sai����֣�����С˳����������:\n"+
"  6����        �����죨ͨ�ԣ����⽱��\n"+
"  6��������    ������  \n"+
"  4���ļ�����һ ״Ԫ���  \n"+
"  5��4         ��  ��\n"+
"  5��������    ��  ��\n"+
"  4��4	       ״Ԫ   1�� ״Ԫ���ϼ�Ǳ��10\n"+
"  1-6��һ	����  2�� ��Ǳ��8\n"+
"  3��4         ����  4�� ��Ǳ��4\n"+	
"  4��һ����(��4��) �Ľ�  8��  ��Ǳ��3\n"+
"  2��4         ����	16��   ��Ǳ��2\n"+
"  1��4 	       һ�� 32�� ��Ǳ��1\n"+
"(��лOcean�����Ҳ����Ļ�������)\n"+
"���⣬״Ԫ��˭�Ǳȴ�С�ģ�˭�õ�����״Ԫ�����õ�����Ľ�Ʒ��\n";
/*}
else{
restring="������"+roomname+"������Ϸ��ʽ����,�㽫�õ��ܷ���\n"+
"��Ʒ(����������õĻ���һҹ֮�������һ��������)\n"+
"������ڲ��Թ����з�����ʲô©��������ϵ\n"+
"Ultra��Cocacola(larnk@usa.net)����Ϸ��������:\n"+
"��Ϸ��������:\n"+
"  ��Ҫjoin���뵽������Ϸ�С�(��joiner���Կ����Ѿ������������)\n"+
"  ���ֵ��㶪ʱ����bp����Ϳ����ˡ�\n"+
"  ���뿪ǰҪ����leave��������뿪��\n"+
"  ��С˳����������:\n"+
"  6����        �����죨ͨ�ԣ�\n"+
"  6��������    ������  \n"+
"  4���ļ�����һ ״Ԫ���  \n"+
"  5��4         ��  ��\n"+
"  5��������    ��  ��\n"+
"  4��4	       ״Ԫ   1�� \n"+
"  1-6��һ	����  2�� \n"+
"  3��4         ����  4�� \n"+	
"  4��һ����(��4��) �Ľ�  8��  \n"+
"  2��4         ����	16��   \n"+
"  1��4 	       һ�� 32�� \n"+
"(��лOcean�����Ҳ����Ļ�������)\n"+
"���⣬״Ԫ��˭�Ǳȴ�С�ģ�˭�õ�����״Ԫ�����õ�����Ľ�Ʒ��\n";
**״Ԫ�ĸ��ӽ�����������,ͬʱ�㿴һ����Щ�������ԸĶ��͸İ�.
}
*/
return restring;
}

int startreal()
  {
  object ob;
  object* pl;
  ob=this_player();
  if (wizardp(ob))
    {
    Realmode=1;
    pl=users();
    tell_room(here,"\n"+HIY+ob->query("name")+"������"+roomname+"�İٱ�����ʽ�򿪣���Ʒ�������֣�\n"NOR);
    return 1;
    }
  return 0;
 }

int stopreal()
  {
  object ob;
  object* pl;
  ob=this_player();
  if (wizardp(ob))
    {
    Realmode=0;
    pl=users();
    tell_room(here,"\n"+HIY+ob->query("name")+"����:"+roomname+
	    "�����ڲ��Ժ�����,�ٱ����յ��ˣ�\n"NOR);
    return 1;
    } 
  return 0;
  }


void pass_token(int index,int passmode)
{
  int me,i,passok;
  me=index-1;
  allow_leave=0;
  passok=0;
  leader=0;
  NowLea=-1;
//  if( passmode==0)
//    {
    for(i=0;i<sizeof(member)-1;i++,index++)
      {
    //  index=index+i;
      if (index>=sizeof(member)) index=index-sizeof(member);
      if(!member[index]) {
	  member=member[0..(index-1)]+member[(index+1)..];
	  continue;
      }
      if(!interactive(member[index])) continue;
      if(query_idle(member[index])>240) continue;
      if(environment(member[index])!=here) continue;

	passok=1;
	leader=member[index];
	break;
      }
    if ((!passok)||(sizeof(member)<minperson))
       {
       allow_start=0;
       tell_room(here,"��������˻��������������˰ɡ�\n");
       return;
       }
    else tell_room(here,"�����ֵ�"+leader->query("name")+"���ˡ�\n");	
//    }
/*
  if(passmode==1)			//
    {
    if (index>=sizeof(member)) index=index-sizeof(member);
    passok=1;
    leader=member[index];
    }
    */
  allow_leave=1;
  NowLea=index;
}

int fyao()		//��ʼҡ����
  {
  object ob;
  int i,j,k;
  ob=this_player();
  i=query_member(ob);

  if(is_busy) return notify_fail("���ż����ٵ�һ�ȣ�\n");

  if(check_member()>=minperson) allow_start=1;

  if (allow_start )	//����������Ļ�allow_start>0
    {
    if (startbp==0)return notify_fail("������û�п�ʼ��\n");
    if (i>0)		//�Ƿ��Ѿ����뵽��Ϸ����
      {
      // check leader.
      if(!leader) leader=ob;
      if(!interactive(leader)) leader=ob;
      if(query_idle(leader)>240) leader=ob;
      if(environment(leader)!=here) leader=ob;
      NowLea=query_member(leader)-1;

      if(ob==leader)	//�Ƿ��ֵ�����
        {
	    do_yao();
	    return 1;
//   	if (do_yao()) return 1;	//��ʼҡ
//	pass_token(i,0);//����һ��ҡ
//	return 1;
 	}
      else notify_fail("��û�ֵ����أ�Ϲ����ʲôѽ��\n");
      }
    else notify_fail("��Ӧ���Ȳμӽ�ȥ���ܺʹ��һ�𲥱���\n");
    }
  else notify_fail("�����˻��������ٵȵȰɡ�\n");
  }

int fjoiner()		//�鿴������Ϸ����
  {		
  object ob;
  int i;
  ob=this_player();
  if (!arrayp(member)||sizeof(member)==0) 
	notify_fail("û���������ﲩ����\n");
  else
    {
    printf("���          ��߽�       һ��  ����  �Ľ�  ����  ����  ״Ԫ\n");
    printf("=============================================================\n");
    for(i=0;i<sizeof(member);i++)
      {
	  if(!member[i]) continue;

      printf("%-14s%-11s%6d%6d%6d%6d%6d%6d\n",
      member[i]->query("name"),member[i]->query_temp("cocacola/dest"),
      member[i]->query_temp("cocacola/g1"),member[i]->query_temp("cocacola/g2"),
      member[i]->query_temp("cocacola/g3"),member[i]->query_temp("cocacola/g4"),
      member[i]->query_temp("cocacola/g5"),member[i]->query_temp("cocacola/g6"),);
      }
    printf("=============================================================\n");
    printf("%-14s%-11s%6d%6d%6d%6d%6d%6d\n",
	    "�ܼ�","",32-Max1,16-Max2,8-Max3,4-Max4,2-Max5,1-Max6); 
    printf("=============================================================\n");
    if(winner)
      printf("���ڵ�״Ԫ������ǣ�%s\n",winner->query("name"));
    if(leader)
      printf("�����ֵ�%s���ˡ�\n",leader->query("name"));
    if(check_member()==0)  game_over(1);
    return 1;
    }
  }

int fleave()		//�뿪��Ϸ
  {
  object ob;
  object nil;
  ob=this_player();
//  if (allow_leave==0 || is_busy) return notify_fail("��ʱ�޷��˳�\n");
  if (is_busy) return notify_fail("��ʱ�޷��˳�\n");
  if (leader && leader!=ob) return notify_fail("�������㲩��ʱ��ſ����˳�\n");
  if (query_member(ob)) 
    {
    pass_token(query_member(ob),1);
    message_vision("$N�뿪�˴�Ҳ��沩����\n",ob);
    Maxperson++;
    delete_member(ob);
    if(ob==winner) winner=0;
    return 1;
    }
  else return notify_fail("�㲢û�м��뵽��Ϸ�а���\n");
  return 1;
  }

int fjoin()		//�μӵ���Ϸ��
  {
  object ob;
  ob=this_player();
  if(check_member()==0)  game_over(1);

  if (startbp==1)return notify_fail("�����Ѿ���ʼ��,�㲻���ټ�����\n");
  if (!(query_member(ob))) 
    {
    if (Maxperson>0) 
      {
      message_vision("$N������ʹ��һ���沩��������\n",ob);
      Maxperson--;
      add_member(ob);
      ob->delete_temp("cocacola");	//׷�Ӵ˾�Ϊ���������������
      ob->set_temp("cocacola/dest","");
      }
    else tell_object(ob,"��һ�����Ѿ����ˣ��㻹��ȥ�𴦿����ɡ�\n");
    }
  else return notify_fail("���Ѿ�����Ϸ���ˣ�\n");
  return 1;
}

int valid_leave(object me, string dir)		//�뿪����
  {
  if( query_member(me) )
    return notify_fail("��Ҫ���뿪�����������뿪���\n"); 
  return 1; 
}

int delete_member(object ob)
  {
  int i;
  if (!arrayp(member)) return 0;
  for (i=0;i<sizeof(member);i++) 
    {
    if (member[i]==ob) 
      {
      member-=({ob});
      ob->delete_temp("cocacola");
      break;
      }
    }
}

int add_member(object ob)
  {
  if (!arrayp(member)) 
    {
    member=({ob});
    leader=ob;
    }
  else 
    {
    member+=({ob});
    if (sizeof(member)>=minperson)  
      {
      allow_start=1;
      if (startbp==1)
        {
        tell_room(environment(leader),"���ˣ��˹��ˣ����Կ�ʼ���ˡ�\n");
        tell_room(environment(leader),leader->query("name")+"�ȶ��ɡ�\n");
        }
      }
    }
  return 1;
  }

int query_member(object ob)
  {
  int i;
  if (!arrayp(member)) return 0;
  return member_array(ob,member)+1; // mon
  
  for (i=0;i<sizeof(member);i++) 
    {
    if (member[i]==ob) 
      {
      return i+1;
      }
    }
  return 0;
}

int do_yao()
  {
  int s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore;
  
  object ob;
  string result1,result,dest;
  ob=this_player();
  getscore=0;
  dest="";
  s1=random(6)+1;
  s2=random(6)+1;
  s3=random(6)+1;
  s4=random(6)+1;
  s5=random(6)+1;
  s6=random(6)+1;
  //������ͳ��
  c1=countit(s1,s2,s3,s4,s5,s6,1);//һ�ĸ���
  c2=countit(s1,s2,s3,s4,s5,s6,2);//���ĸ���
  c3=countit(s1,s2,s3,s4,s5,s6,3);//���ĸ���
  c4=countit(s1,s2,s3,s4,s5,s6,4);
  c5=countit(s1,s2,s3,s4,s5,s6,5);
  c6=countit(s1,s2,s3,s4,s5,s6,6);

if(c1==6||c2==6||c3==6||c4==6||c5==6||c6==6){
  getaward=6;	
  if(c1==6) {
	dest="������(һ)";
	getscore=1201;
  	}	
  if(c2==6) {
	dest="������(��)";
	getscore=1202;
	}

  if(c3==6){
	 dest="������(��)";
	getscore=1203;
	}
  if(c5==6) 
	{dest="������(��)";
	getscore=1204;
	}
  if(c6==6) 
	{dest="������(��)";
	getscore=1205;
	}
  if(c4==6) {
	dest="������(ͨ��)";
	getscore=1206;
	}

}

else if(c4==5){
  getaward=6;	
  if(c1==1){
	dest="����һ";
	getscore=1102;
  }
  if(c2==1){
	dest="������";
	getscore=1103;
  }
  if(c3==1){
	dest="������";
	getscore=1104;
  }
  if(c5==1){
	dest="������";
	getscore=1105;
  }
  if(c6==1){
	dest="������";
	getscore=1106;
  }

}


else if(c6==5){
  getaward=6;	
  if(c1==1){
	dest="����(��)��һ";
	getscore=1002;
  }
  if(c2==1){
	dest="����(��)����";
	getscore=1003;
  }
  if(c3==1){
	dest="����(��)����";
	getscore=1004;
  }
  if(c5==1){
	dest="����(��)����";
	getscore=1005;
  }
  if(c4==1){
	dest="����(��)����";
	getscore=1006;
  }

}


else if(c5==5){
  getaward=6;	
  if(c1==1){
	dest="����(��)��һ";
	getscore=902;
  }
  if(c2==1){
	dest="����(��)����";
	getscore=903;
  }
  if(c3==1){
	dest="����(��)����";
	getscore=904;
  }
  if(c6==1){
	dest="����(��)����";
	getscore=905;
  }
  if(c4==1){
	dest="����(��)����";
	getscore=906;
  }

}

else if(c3==5){
  getaward=6;	
  if(c1==1){
	dest="����(��)��һ";
	getscore=802;
  }
  if(c2==1){
	dest="����(��)����";
	getscore=803;
  }
  if(c5==1){
	dest="����(�� )����";
	getscore=804;
  }
  if(c6==1){
	dest="����(��)����";
	getscore=805;
  }
  if(c4==1){
	dest="����(��)����";
	getscore=806;
  }

}


else if(c2==5){
  getaward=6;	
  if(c1==1){
	dest="����(��)��һ";
	getscore=702;
  }
  if(c3==1){
	dest="����(��)����";
	getscore=703;
  }
  if(c5==1){
	dest="����(��)����";
	getscore=704;
  }

  if(c6==1){
	dest="����(��)����";
	getscore=705;
  }
  if(c4==1){
	dest="����(��)����";
	getscore=706;
  }

}

else if(c1==5){
  getaward=6;	
  if(c2==1){
	dest="����(һ)����";
	getscore=602;
  }
  if(c3==1){
	dest="����(һ)����";
	getscore=603;
  }
  if(c5==1){
	dest="����(һ)����";
	getscore=604;
  }

  if(c6==1){
	dest="����(һ)����";
	getscore=605;
  }
  if(c4==1){
	dest="����(һ)����";
	getscore=606;
  }

}

else if (c4==4){
  getaward=6;	
  if((s1+s2+s3+s4+s5+s6-16)==2){
	dest="״Ԫ���";
	getscore=1300;
	}
  if((s1+s2+s3+s4+s5+s6-16)==12){
	dest="״Ԫ��ʮ��";
	getscore=512;
	}
  if((s1+s2+s3+s4+s5+s6-16)==11){
	dest="״Ԫ��ʮһ";
	getscore=511;
	}
  if((s1+s2+s3+s4+s5+s6-16)==10){
	dest="״Ԫ��ʮ";
	getscore=510;
	}
  if((s1+s2+s3+s4+s5+s6-16)==9){
	dest="״Ԫ����";
	getscore=509;
	}
  if((s1+s2+s3+s4+s5+s6-16)==8){
	dest="״Ԫ����";
	getscore=508;
	}
  if((s1+s2+s3+s4+s5+s6-16)==7){
	dest="״Ԫ����";
	getscore=507;
	}
  if((s1+s2+s3+s4+s5+s6-16)==6){
	dest="״Ԫ����";
	getscore=506;
	}
  if((s1+s2+s3+s4+s5+s6-16)==5){
	dest="״Ԫ����";
	getscore=505;
	}
  if((s1+s2+s3+s4+s5+s6-16)==4){
	dest="״Ԫ����";
	getscore=504;
	}
  if((s1+s2+s3+s4+s5+s6-16)==3){
	dest="״Ԫ����";
	getscore=503;
	}

}


else if(c1==4||c2==4||c3==4||c5==4||c6==4){
  getaward=3;	
  if (c4==2){
	getscore=302;
	dest="�Ľ�������";
	}
  if(c4==1){
	getscore=301;
	dest="�Ľ���һ��";
	}
  if(c4==0){
	getscore=300;
	dest="�Ľ�";
	}
}

else if(c4==3) {
	getaward=4;
	getscore=400;
	dest="����";
	}
else if(c4==2) {
	getaward=2;
	getscore=200;
	dest="����";
	}

else if (c4==1){
  if(c1==1&&c2==1&&c3==1&&c5==1&&c6==1) {
	getaward=5;
	getscore=500;
	dest="����";
	}
  else {
	getaward=1;
	getscore=100;
	dest="һ��";
	}
}
else {
	getaward=0;
	getscore=0;
	dest="��������ѽ��ʲô������Ŷ����\n";
}
	
  result=" -------  -------  -------  -------  -------  -------\n"+
      "|       ||       ||       ||       ||       ||       |\n"+
      "|   "+checkcolor(s1)+"%d"+NOR+
      "   ||   "+checkcolor(s2)+"%d"+NOR+
      "   ||   "+checkcolor(s3)+"%d"+NOR+
      "   ||   "+checkcolor(s4)+"%d"+NOR+
      "   ||   "+checkcolor(s5)+"%d"+NOR+
      "   ||   "+checkcolor(s6)+"%d"+NOR+
      "   |\n"+  
      "|       ||       ||       ||       ||       ||       |\n"+  
      " -------  -------  -------  -------  -------  -------\n";  
  result=sprintf(result,s1,s2,s3,s4,s5,s6);
  result1="��Ȼ�Ǹ�"+dest+"��";
  message_vision("$Nץ����������,����������ƴ��ҡ�����л������дʵ���\n"+
  "�����飬�����飮���������������ˣ�����\n",ob);

  is_busy=1;
  call_out("do_yao1",1+random(2),ob,result,result1,
	  getaward,getscore,dest);

  return 1;
  }
  
void do_yao1(object ob, string re,string re1, int getaward,
	int getscore, string dest)
{
    if(!ob) {
	is_busy=0;
	return;
    }
    message_vision(re,ob);
    call_out("do_yao2",2+random(3),ob,re1,getaward,getscore,dest);
}

void do_yao3() {is_busy=0;}
void do_yao2(object ob, string re1,int getaward,int getscore,string dest)
{
    int s1;
    if(!ob) {
	is_busy=0;
	return;
    }
    message_vision(re1,ob);
    s1=getit(ob,getaward,getscore,dest);
    if(!s1) {
	pass_token(query_member(ob),0);
    }
    call_out("do_yao3",1+random(2));
}

string checkcolor(int i)		//���ӵ�һ���Ķ��Ǻ�ɫ��
  {
  if(i==4) return HIR;
  else if(i==1) return HIR;
  else return "";
  }

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
  {  //�������
  int i;
  i=0;
  if (s1==sd) i++;
  if (s2==sd) i++;
  if (s3==sd) i++;
  if (s4==sd) i++;
  if (s5==sd) i++;
  if (s6==sd) i++;
  return i;
}

int getit(object ob,int getaward,int getscore,string dest)
  {
  object* play,nil;
  int nowat;


/*  if (getaward>(ob->query_temp("cocacola/maxaward"))) 
    {
    ob->set_temp("cocacola/maxaward",getaward ); 
    ob->set_temp("cocacola/dest",dest);
    }
  if (getscore>(ob->query_temp("cocacola/maxscore"))) 
     ob->set_temp("cocacola/maxscore",getscore); 
*/
  if (getaward==1) 
    {
    if (Max1<=0 )
      {
      tell_room(environment(ob),CYN"��ϧ����һ����ȫ�������ˣ�����Ŭ���ɣ�����\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g1",ob->query_temp("cocacola/g1")+1); 
      if(Realmode) 
        {
//        ob->add("combat_exp",100);
	ob->add("potential",1);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 1 pot.\n");
        message_vision(HIY"$N����һ��һ������Ǳ��1�㣡\n"NOR,ob);
        Max1--;
        }
      else 	
        message_vision(CYN"$N����һ��һ��������ʦ��û�ѱ��Ҵ򿪣����ܵý�Ʒ.\n"NOR,ob); 
      }
    }
  if (getaward==2) 
    {
    if (Max2<=0 )
      {
      tell_room(environment(ob),CYN"��ϧ����������ȫ�������ˣ�����Ŭ���ɣ�����\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g2",ob->query_temp("cocacola/g2")+1); 
      if(Realmode) 
        {
//	ob->add("combat_exp",200);
	ob->add("potential",2);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 2 pot.\n");
	message_vision(HIY"$N��������һ������Ǳ��2�㣡\n"NOR,ob);
	Max2--;
	}
      else 	
        message_vision(CYN"$N��������һ��������ʦ��û�ѱ��Ҵ򿪣����ܵý�Ʒ.\n"NOR,ob); 
      }
    }
  if (getaward==3) 
    {
    if (Max3<=0 )
      {
      tell_room(environment(ob),CYN"��ϧ�����Ľ���ȫ�������ˣ�����Ŭ���ɣ�����\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g3",ob->query_temp("cocacola/g3")+1); 
      if(Realmode) 
        {
//	ob->add("combat_exp",500);
	ob->add("potential",3);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 3 pot.\n");
	message_vision(HIY"$N�����Ľ�һ������Ǳ��3�㣡\n"NOR,ob);
	Max3--;
	}
      else 	
	message_vision(CYN"$N�����Ľ�һ��������ʦ��û�ѱ��Ҵ򿪣����ܵý�Ʒ.\n"NOR,ob); 
	give_cake(ob);
      }
    }
  if (getaward==4) 
    {
    if (Max4<=0 )
      {
      tell_room(environment(ob),CYN"��ϧ����������ȫ�������ˣ�����Ŭ���ɣ�����\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g4",ob->query_temp("cocacola/g4")+1); 
      if(Realmode) 
        {
//	ob->add("combat_exp",1000);
	ob->add("potential",4);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 4 pot.\n");
	message_vision(HIY"$N��������һ������Ǳ��4�㣡\n"NOR,ob);
	Max4--;
	}
      else 	
        message_vision(CYN"$N��������һ��������ʦ��û�ѱ��Ҵ�,���ܵý�Ʒ.\n"NOR,ob); 
      }
    }
  if (getaward==5) 
    {
    if (Max5<=0 ) 
      {
      tell_room(environment(ob),CYN"��ϧ����������ȫ�������ˣ�����Ŭ���ɣ�����\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g5",ob->query_temp("cocacola/g5")+1); 
      if(Realmode) 
        {
 //       ob->add("combat_exp",1000);
        ob->add("potential",8);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 8 pot.\n");
        message_vision(
		HIY"$N��������һ������Ǳ��8�㣡\n"NOR,ob);
        Max5--;
        }
      else 	 
        message_vision(CYN"$N��������һ��������ʦ��û�ѱ��Ҵ򿪣����ܵý�Ʒ.\n"NOR,ob); 
	give_cake(ob);
      }
    }
  if (getaward==6) 
    {
    Max6=0;
    if ((getscore==1202)||(getscore==1203)||(getscore==1205)||(getscore==1206))
      {
      play=users();
      tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	      "============\n���ң����ң�"+ob->query("name")+"������"+dest+"�����Ӵ��˳�����Ȧ������\n"NOR);
      Maxperson++;
      delete_member(ob);
      if(ob==winner) winner=0;
      return 0;	      
      }
    if ((getscore==1201)||(getscore==1204))
      {
      winner=ob;
            
      play=users();
      tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
     	      "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"����ͨɱ,̫�����ˣ�����\n"NOR); 
      
      game_over(0);	
      return 1;	 
      }
     

      if (ob->query_temp("cocacola/g6")==0)
        ob->set_temp("cocacola/g6",ob->query_temp("cocacola/g6")+1);
      ob->set_temp("cocacola/score",getscore);

    if (jinhua==1)
      {
      play=users();
      tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
     	      "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"����\n"+
	      "�����Ѿ����˲���״Ԫ���,������״Ԫ�Ѿ�û�������ˣ�����\n"NOR); 
      return 0;
      }

    if (getscore==1300)
      {
      winner=ob;
      play=users();
      tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	      "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"̫������,���ڿ��Ǿ��Ե�״Ԫ�ˣ���"NOR);
      jinhua=1;
      Max5=0;
/*    ob->add("combat_exp",2000);
*/  
      if(Realmode) {
      ob->add("potential",10);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 10 pot.\n");
      message_vision(HIY"$N����״Ԫһ������Ǳ��10�㣡\n"NOR,ob);
      }
	give_cake(ob);
     //** ����뽱��
      return 0;		        
      }

      play=users();
      tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	      "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"����"NOR);



      if(!winner)
        {
        winner=ob;
        play=users();
        tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	        "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"������Ϊ"+roomname+"����״Ԫ������\n"NOR);
        }
      else
        {
        nowat=getnewzy();
        if (ob==winner)
          {
          play=users();
          tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	        "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"������Ϊ"+roomname+"����״Ԫ������\n"NOR);
          }
        else
          {
          play=users();
          tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	        "============\nĿǰ��״Ԫ�ǣ�"+winner->query("name")+"������\n"NOR);
          } 
        }	
   



    if(Realmode) 
      {
//      ob->add("combat_exp",2000);
      ob->add("potential",10);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 10 pot.\n");
//      message_vision(HIY"$N����״Ԫһ��,�������2000��,Ǳ��50��,�����ԣ����ǣ����Ը�һ��.\n"NOR,ob);
      message_vision(HIY"$N����״Ԫһ������Ǳ��10�㣡\n"NOR,ob);
      }
    else 	
      message_vision(CYN"$N����״Ԫһ��������ʦ��û�ѱ��Ҵ򿪣����ܵý�Ʒ.\n"NOR,ob); 
	give_cake(ob);

    }

/*
  if(getaward>=6)
    {
    if(!objectp(winner))
      {
      winner=ob;
      play=users();
      tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	      "============\n��ϲ����ϲ��"+ob->query("name")+"������"+dest+"!!��Ϊ"+roomname+"����״Ԫ!!!\n"NOR);
      }
    else 
      {	
      if(ob!=winner&&getscore>winner->query_temp("cocacola/maxscore"))
        {
        winner=ob;
        play=users();
        tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
	      "============\n��ϲ����ϲ!"+ob->query("name")+"������"+dest+"!!��Ϊ"+roomname+"����״Ԫ!!!\n"NOR);
        }
      }
    }
*/

  if (Max1+Max2+Max3+Max4+Max5+Max6==0)
    {
    game_over(0);    
    return 0;
    }
  return 0;

  }

void game_over(int i)
  {
  object *play,ob;
  ob=winner;
  play=users();
  tell_room(here,HIY"\n\n[����������Ϣ]\n=================================="+
       "============\n"+roomname+"�Ĳ��������ˣ�����\n"NOR);
  if(!i) {
      if(winner) {
        tell_room(here,HIY"��ϲ����ϲ��"+ob->query("name")+"����״Ԫ��\n"NOR);
	if(Realmode) {
	winner->add("combat_exp",200);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 200 dx.\n");
	tell_room(here,HIY+ob->query("name")+"�õ�����ʮ����У�\n"NOR);
	}
	give_cake(ob);
      }
//  if (jinhua!=1)
//    {
  //** ������������״Ԫ�Ľ���.
 //   }
  //���û�������϶�״Ԫ������������ڿ���������
  }

  startbp=0;stopbp=0;
  Max1=32;Max2=16;Max3=8;Max4=4;Max5=2;Max6=1;
  NowLea=-1;jinhua=0;
  member=0;
  Realmode=0;
        Maxperson=12;
	minperson=4;
	allow_leave=1;
	allow_start=0;
  startbp=0;
  winner=0;
  }

int getnewzy()
  {
  int i,nowat,maxscore;
  if (!arrayp(member)) return 0;
  maxscore=member[0]->query_temp("cocacola/score");    
  nowat=0;
  for (i=0;i<sizeof(member);i++) 
    {
    if (maxscore<member[i]->query_temp("cocacola/score"))
      {
      maxscore=member[i]->query_temp("cocacola/score");    
      nowat=i;  
      winner=member[i];
      }    
    }
  return nowat+1; 
  }
