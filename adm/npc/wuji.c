//Cracked by Roath


inherit NPC;

string *banned_name = ({
	"��", "��", "��", "��", "��", "��", "������", "��Сƽ", "����", "���Ż�",
	"�Լ�", "ĳ��", "ʬ��", "����","����", "����", "���",
	"�����", "ȥ���", "ë��", "��ʦ", "�����̵�",
       "����", "����", "��������","��ɮ","����","ɮ",
});

int check_legal_name(string name);

void create()
{
        set_name("�����޼�", ({"zhangsun wuji","minister","wuji","zhangsun"}));
        set("gender", "����");
        set("title","��������");
        set("age", 50);
        set("attitude", "friendly");
        set("combat_exp", 250000);
    set("long", "����apply���Կ���ʹ�÷�����\n");





        set("per", 30);
        setup();

        carry_object("/d/gao/obj/changpao")->wear();

}

void init()
{
   ::init();
   add_action("do_newname", "newname");
   add_action("do_apply", "apply");
   add_action("do_confirm","confirm");
   this_player()->delete_temp("new_rank");

}
       
int do_apply(string arg)
{
  string type,rank;   
  object me=this_player();
  string msg="��׼����";
  int afford;

   if (!arg) return notify_fail(@LONG
��ʽ�� apply <���> to <��ν>
��𣯼۸񣯵���Ҫ��
self        ���Լ��ĳƺ�      ��ʮ���ƽ�   һ����
self_rude   ���Լ��Ĵ�³�ƺ�  ��ʮ���ƽ�   һ����
respect     ���˶��Լ������  ��ʮ���ƽ�   �����

�֣�����ʹ�ò�ǡ���ĳ�ν����Ȼ�ƺ���ȡ������ʮ��
���ӾͰװ����ˡ�����ǡ����������������ɾ�����

LONG);
  if (sscanf(arg,"%s to %s",type,rank)!=2)   return notify_fail(@LONG
��ʽ�� apply <���> to <��ν>
��𣯼۸�
self          ���Լ��ĳƺ�         ��ʮ���ƽ�
self_rude     ���Լ��Ĵ�³�ƺ�     ��ʮ���ƽ�
respect       ���˶��Լ������     ��ʮ���ƽ�

�֣�����ʹ�ò�ǡ���ĳ�ν����Ȼ�ƺ���ȡ������ʮ��
���ӾͰװ����ˡ�����ǡ����������������ɾ�����

LONG);
  
  if (type!="self" && type!="respect" && type!="self_rude")
    return notify_fail("���������������͵ĳƺ���\n");

  if (type!="respect" && me->query("daoxing")<100000) 
    return notify_fail("�������ô�ͣ�������û����˵���㣬����Ҳ�ա�\n");
  if ( type=="respect" && me->query("daoxing")<500000)
    return notify_fail("�㱾�컹���������˲������������еġ�\n");

  if( !(afford=me->can_afford(500000)) )  {
     write("�����Ǯ������\n");
     return 1; 
  } else if( afford == 2 )  {
      write("�ֽ��ף�������Ʊ��������ֽ𲻹���\n");
      return 1;
  }

  switch (type) {
    case "self" : msg+="���Լ��ĳƺ������ڵġ�"+RANK_D->query_self(me);break;
    case "self_rude" : msg+="���Լ��Ĵ�³�ƺ������ڵġ�"+RANK_D->query_self_rude(me);break;
    case "respect" :  msg+="���˶��Լ�����ƴ����ڵġ�"+RANK_D->query_respect(me);break;
  }
  msg+="���ĳɡ�"+rank+"������������(confirm)\n";
  write(msg);
  me->set_temp("new_rank/type",type);
  me->set_temp("new_rank/ready",1);
  me->set_temp("new_rank/rank",rank);
  return 1;
}

int do_confirm() {
  object me=this_player();
  int afford;

  if (!me->query_temp("new_rank/ready"))
     return notify_fail("��Ҫȷ��ʲô��\n");

  if( !(afford=me->can_afford(500000)) )  {
       write("�����Ǯ������\n");
       return 1; 
  } else if( afford == 2 )  {
      write("�ֽ��ף�������Ʊ��������ֽ𲻹���\n");
      return 1;
  }

  message_vision("$N�ó���ʮ�����ӣ�������$n��\n",me,this_object());
  message_vision("$N���˵�ͷ���ó�һ�ݾ���д�˼��ʡ�\n",this_object());
  me->pay_money(500000);
  if (me->query_temp("new_rank/rank")=="cancel")
     me->delete("rank_info/"+me->query_temp("new_rank/type"));
  else 
     me->set("rank_info/"+me->query_temp("new_rank/type"),me->query_temp("new_rank/rank"));
  write("�Ķ���ϡ�\n");
 log_file("change_rank",me->query("id")+" changes "+me->query_temp("new_rank/type")+" to "
      +me->query_temp("new_rank/rank")+" on "+ctime(time())+".\n");
 
 me->delete_temp("new_rank");
  return 1;
}


// modified by mudring@sjsh......
int do_newname(string arg)
{
   object me=this_player();
  int afford;
   string result;

  if (!arg) return notify_fail(@LONG
��ʽ�� newname <������> 
�۸� ��ǧ���ƽ�(����Я��)

LONG);


//150       arg = CONVERT_D->input(arg,me);

	if( !check_legal_name(arg) ) {

		write("����������ֲ��Ϸ�!����������!\n");
		return 1;
	    } else
        if ( stringp(result = NAME_D->invalid_new_name(arg)) )
        {
                write("�Բ���" + result);
                return 1;
        } else
{
 if( !(afford=me->can_afford(80000000)) )  {
     write("�����Ǯ������\n");
	return 1;
  } 

  message_vision("$N�ó���ǧ�����ӣ�������$n��\n",me,this_object());
  message_vision("$N���˵�ͷ���ó�һ�ݾ���д�˼��ʡ�\n",this_object());
  me->pay_money(80000000);
   NAME_D->remove_name(me->query("name"), me->query("id"));
  me->set("name",arg);
   NAME_D->map_name(me->query("name"), me->query("id"));
    write("������ָ�����ϡ�\n");
	return 1;
}
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("�Բ�������������ֱ�����һ�����������֡�\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�Բ�������������ֲ����ÿ����ַ���\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}
	return 1;

}
